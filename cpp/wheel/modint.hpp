#pragma once
#include <iostream>
#include <compare>

// MOD MUST be prime
template<int MOD>
struct modint {
    int _v;

    modint() : _v(0) {}
    modint(long long v) {
        if (v < 0) v = v % MOD + MOD;
        _v = v % MOD;
    }
    std::strong_ordering operator<=>(const modint &) const = default;
    // operator int() const { return _v; }
    // operator long long() const { return _v; }
    int val() const { return _v; }

    modint operator+(const modint& other) const {
        int res = _v + other._v;
        if (res >= MOD) res -= MOD;
        return modint(res);
    }
    modint& operator+=(const modint& other) {
        *this = *this + other;
        return *this;
    }
    modint operator-(const modint& other) const {
        int res = _v - other._v;
        if (res < 0) res += MOD;
        return modint(res);
    }
    modint& operator-=(const modint& other) {
        *this = *this - other;
        return *this;
    }

    modint operator*(const modint& other) const { return modint(1LL * _v * other._v % MOD); }
    modint& operator*=(const modint& other) {
        *this = *this * other;
        return *this;
    }

    modint pow(long long n) const {
        modint res = 1, base = *this;
        while (n > 0) {
            if (n & 1) res *= base;
            base *= base;
            n >>= 1;
        }
        return res;
    }

    // divide (multiply by inverse)
    modint inv() const { return pow(MOD - 2); }

    modint operator/(const modint& other) const { return *this * other.inv(); }
    modint& operator/=(const modint& other) {
        *this = *this / other;
        return *this;
    }

    modint& operator++() {
        *this += 1;
        return *this;
    }
    modint operator++(int) {
        modint tmp = *this;
        ++*this;
        return tmp;
    }
    modint& operator--() {
        *this -= 1;
        return *this;
    }
    modint operator--(int) {
        modint tmp = *this;
        --*this;
        return tmp;
    }
};