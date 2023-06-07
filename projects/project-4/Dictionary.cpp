#include "Dictionary.h"
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

void removeNonLetters(string& s);

class DictionaryImpl {
public:
    DictionaryImpl(int maxBuckets);
    void insert(string word);
    void lookup(string letters, void callback(string)) const;

private:
    vector<list<string>> m_buckets;
    size_t m_numBuckets;

    size_t hash(const string& s) const;
    bool isAnagram(const string& s1, const string& s2) const;
};

DictionaryImpl::DictionaryImpl(int maxBuckets) {
    m_numBuckets = maxBuckets;
    m_buckets.resize(m_numBuckets);
}

void DictionaryImpl::insert(string word) {
    removeNonLetters(word);
    if (!word.empty()) {
        size_t bucket = hash(word) % m_numBuckets;
        m_buckets[bucket].push_back(word);
    }
}

void DictionaryImpl::lookup(string letters, void callback(string)) const {
    if (callback == nullptr)
        return;

    removeNonLetters(letters);
    if (letters.empty())
        return;

    size_t bucket = hash(letters) % m_numBuckets;
    for (const auto& word : m_buckets[bucket]) {
        if (isAnagram(letters, word)) {
            callback(word);
        }
    }
}

size_t DictionaryImpl::hash(const string& s) const {
    typename std::hash<std::string> str_hash;
    string sorted = s;
    sort(sorted.begin(), sorted.end());
    return str_hash(sorted);
}

bool DictionaryImpl::isAnagram(const string& s1, const string& s2) const {
    if (s1.size() != s2.size())
        return false;

    string sorted1 = s1;
    sort(sorted1.begin(), sorted1.end());

    string sorted2 = s2;
    sort(sorted2.begin(), sorted2.end());

    return sorted1 == sorted2;
}

void removeNonLetters(string& s) {
    string::iterator to = s.begin();
    for (string::const_iterator from = s.begin(); from != s.end(); from++) {
        if (isalpha(*from)) {
            *to = tolower(*from);
            to++;
        }
    }
    s.erase(to, s.end());  // chop everything off from "to" to end.
}

Dictionary::Dictionary(int maxBuckets) {
    m_impl = new DictionaryImpl(maxBuckets);
}

Dictionary::~Dictionary() {
    delete m_impl;
}

void Dictionary::insert(string word) {
    m_impl->insert(word);
}

void Dictionary::lookup(string letters, void callback(string)) const {
    m_impl->lookup(letters, callback);
}