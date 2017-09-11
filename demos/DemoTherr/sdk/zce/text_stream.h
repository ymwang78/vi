#pragma once

#include <zce/zce_config.h>
#include <map>

/************************************************************************/
/* Comparator for case-insensitive comparison in STL assos. containers  */
/************************************************************************/
struct ZCE_API ci_less : std::binary_function<std::string, std::string, bool>
{
    // case-independent (ci) compare_less binary function
    struct nocase_compare : public std::binary_function<unsigned char, unsigned char, bool>
    {
        bool operator() (const unsigned char& c1, const unsigned char& c2) const {
            return tolower(c1) < tolower(c2);
        }
    };

    bool operator() (const std::string & s1, const std::string & s2) const {
        return std::lexicographical_compare
        (s1.begin(), s1.end(),   // source range
            s2.begin(), s2.end(),   // dest range
            nocase_compare());  // comparison
    }
};

struct ZCE_API TEXT_HEADER
{
    enum TEXT_HEADER_E {
        TEXT_HEADER_UNKNOW,
        TEXT_HEADER_REQUEST,
        TEXT_HEADER_RESPONSE
    };

    TEXT_HEADER(TEXT_HEADER_E header_type = TEXT_HEADER_UNKNOW);

    const std::string& exparam(const std::string& parameter)const;

    void exparam(const std::string& parameter, const std::string& value);

    std::map<std::string, std::string, ci_less>& exparam() { return exparam_; }

    void exparam(const std::map<std::string, std::string, ci_less>& param) { exparam_ = param; }

    unsigned header_length() const { return header_length_; }

    void header_length(int len) { header_length_ = len; }

    unsigned body_length() const { return body_length_; }

    void body_length(int length);

    TEXT_HEADER_E header_type_;

protected:

    static const std::string emptystr;

    static const std::string content_length;

    std::map<std::string, std::string, ci_less> exparam_;

    unsigned header_length_;

    unsigned body_length_;
};
