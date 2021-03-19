
#ifndef LZ77CODE_HPP
#define LZ77CODE_HPP

struct lz77Code {
    private:
        size_t p, l;
        char c;
    public:
        lz77Code(size_t p, size_t l , char c);
};

#endif /* LZ77CODE_HPP */