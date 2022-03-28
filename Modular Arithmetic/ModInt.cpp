template <int M>
struct Modint {
  public:
    static constexpr int mod() { return M; }
 
    Modint() : _v(0) {}
 
    template <class T>
    Modint(T v) {
        long long x = (long long)(v % (long long)(Umod()));
        if (x < 0) x += Umod();
        _v = (unsigned int)(x);
    }
 
    Modint(bool v) { _v = ((unsigned int)(v) % Umod()); }
 
    unsigned int val() const { return _v; }
 
    Modint& operator++() {
        _v++;
        if (_v == Umod()) _v = 0;
        return *this;
    }
    Modint& operator--() {
        if (_v == 0) _v = Umod();
        _v--;
        return *this;
    }
    Modint operator++(int) {
        Modint result = *this;
        ++*this;
        return result;
    }
    Modint operator--(int) {
        Modint result = *this;
        --*this;
        return result;
    }
 
    Modint& operator+=(const Modint& rhs) {
        _v += rhs._v;
        if (_v >= Umod()) _v -= Umod();
        return *this;
    }
    Modint& operator-=(const Modint& rhs) {
        _v -= rhs._v;
        if (_v >= Umod()) _v += Umod();
        return *this;
    }
    Modint& operator*=(const Modint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % Umod());
        return *this;
    }
    Modint& operator/=(const Modint& rhs) { return *this = *this * rhs.inv(); }
 
    Modint operator+() const { return *this; }
    Modint operator-() const { return Modint() - *this; }
 
    Modint pow(long long n) const {
        assert(0 <= n);
        Modint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    Modint inv() const {
        assert(_v);
        return pow(Umod() - 2);
    }
 
    friend Modint operator+(const Modint& lhs, const Modint& rhs) { return Modint(lhs) += rhs; }
    friend Modint operator-(const Modint& lhs, const Modint& rhs) { return Modint(lhs) -= rhs; }
    friend Modint operator*(const Modint& lhs, const Modint& rhs) { return Modint(lhs) *= rhs; }
    friend Modint operator/(const Modint& lhs, const Modint& rhs) { return Modint(lhs) /= rhs; }
    friend bool operator==(const Modint& lhs, const Modint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const Modint& lhs, const Modint& rhs) { return lhs._v != rhs._v; }
    friend bool operator<(const Modint& lhs, const Modint& rhs) { return lhs._v < rhs._v; }
    friend bool operator>(const Modint& lhs, const Modint& rhs) { return lhs._v > rhs._v; }
    friend bool operator<=(const Modint& lhs, const Modint& rhs) { return lhs._v <= rhs._v; }
    friend bool operator>=(const Modint& lhs, const Modint& rhs) { return lhs._v >= rhs._v; }
    friend string to_string(const Modint& rhs) { return to_string(rhs.val()); }
    friend std::ostream& operator<<(std::ostream& os, const Modint& a) { os << to_string(a); return os; }
    
  private:
    unsigned int _v;
    static constexpr unsigned int Umod() { return M; }
};
