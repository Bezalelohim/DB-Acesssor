#include <openssl/bio.h>
#include <openssl/evp.h>
#include<string>
#include<vector>
#include<stdexcept>
#include<iostream>


std::string sha1(const std::string &input)
{
    BIO * p_bio_md  = nullptr;
    BIO * p_bio_mem = nullptr;

    try
    {
        // make chain: p_bio_md <-> p_bio_mem
        p_bio_md = BIO_new(BIO_f_md());
        if (!p_bio_md) throw std::bad_alloc();
        BIO_set_md(p_bio_md, EVP_sha1());

        p_bio_mem = BIO_new_mem_buf((void*)input.c_str(), input.length());
        if (!p_bio_mem) throw std::bad_alloc();
        BIO_push(p_bio_md, p_bio_mem);

        // read through p_bio_md
        // read sequence: buf <<-- p_bio_md <<-- p_bio_mem
        std::vector<char> buf(input.size());
        for (;;)
        {
            auto nread = BIO_read(p_bio_md, buf.data(), buf.size());
            if (nread  < 0) { throw std::runtime_error("BIO_read failed"); }
            if (nread == 0) { break; } // eof
        }

        // get result
        char md_buf[EVP_MAX_MD_SIZE];
        auto md_len = BIO_gets(p_bio_md, md_buf, sizeof(md_buf));
        if (md_len <= 0) { throw std::runtime_error("BIO_gets failed"); }

        std::string result(md_buf, md_len);

        // clean
        BIO_free_all(p_bio_md);

        return result;
    }
    catch (...)
    {
        if (p_bio_md) { BIO_free_all(p_bio_md); }
        throw;
    }
}
