#pragma once
#ifndef __ZCE_STRING__
#define __ZCE_STRING__

#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

namespace zce
{
    inline void replace(std::string &strBase, const std::string& strSrc, const std::string& strDes, bool bReplaceAll)
    {
        std::string::size_type pos = 0;
        std::string::size_type srcLen = strSrc.size();
        std::string::size_type desLen = strDes.size();
        pos = strBase.find(strSrc, pos);
        while (pos != std::string::npos) {
            strBase.replace(pos, srcLen, strDes);
            pos = strBase.find(strSrc, (pos + desLen));

            if (!bReplaceAll) {
                break;
            }
        }
    }

    template<typename T>
    inline std::string to_string(T value)
    {
        std::stringstream ss;
        ss << value;
        return ss.str();
    }

    template<>
    inline std::string to_string<const std::string&>(const std::string& str)
    {
        return str;
    }

    template<>
    inline std::string to_string<bool>(bool _value)
    {
        return _value ? "true" : "false";
    }

    template<typename T1, typename T2>
    inline std::string to_string(T1 p1, T2 p2)
    {
        std::ostringstream stream;
        stream << p1 << p2;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3>
    inline std::string to_string(T1 p1, T2 p2, T3 p3)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4 << p5;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4 << p5 << p6;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4 << p5 << p6 << p7;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
        return stream.str();
    }

    template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
    inline std::string to_string(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9)
    {
        std::ostringstream stream;
        stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << p9;
        return stream.str();
    }

    inline void trim(std::string& _str, bool _left = true, bool _right = true, const std::string& whiestr = " \t\r")
    {
        if (_right) _str.erase(_str.find_last_not_of(whiestr) + 1);
        if (_left) _str.erase(0, _str.find_first_not_of(whiestr));
    }

    template<typename T>
    inline T parse_value(const std::string& _value)
    {
        std::istringstream stream(_value);
        T result;
        stream >> result;
        if (stream.fail())
            return T();
        else
        {
            int item = stream.get();
            while (item != -1)
            {
                if (item != ' ' && item != '\t')
                    return T();
                item = stream.get();
            }
        }
        return result;
    }

    inline bool parse_bool(const std::string& _value)
    {
        if (_value == "True" || _value == "true" || _value == "TRUE" || _value == "1")
            return true;
        return false;
    }

    inline char parse_int8 (const std::string& _value)
    {
        return (char)parse_value<char>(_value);
    }

    inline unsigned char parse_uint8(const std::string& _value)
    {
        return (unsigned char)parse_value<unsigned char>(_value);
    }

    inline short parse_int16(const std::string& _value)
    {
        return parse_value<short>(_value);
    }

    inline unsigned short parse_uint16(const std::string& _value)
    {
        return parse_value<unsigned short>(_value);
    }

    inline int parse_int32(const std::string& _value)
    {
        return parse_value<int>(_value);
    }

    inline unsigned int parse_uint32(const std::string& _value)
    {
        return parse_value<unsigned int>(_value);
    }

    inline size_t parse_sizet(const std::string& _value)
    {
        return parse_value<size_t>(_value);
    }

    inline float parse_float(const std::string& _value)
    {
        return parse_value<float>(_value);
    }

    inline double parse_double(const std::string& _value)
    {
        return parse_value<double>(_value);
    }

    template<typename T1, typename T2>
    inline T1 parse_bind2(const std::string& _value)
    {
        T2 p1, p2;
        std::istringstream stream(_value);
        stream >> p1 >> p2;
        if (stream.fail())
            return T1();
        else
        {
            int item = stream.get();
            while (item != -1)
            {
                if (item != ' ' && item != '\t')
                    return T1();
                item = stream.get();
            }
        }
        return T1(p1, p2);
    }

    template<typename T1, typename T2>
    inline T1 parse_bind3(const std::string& _value)
    {
        T2 p1, p2, p3;
        std::istringstream stream(_value);
        stream >> p1 >> p2 >> p3;
        if (stream.fail())
            return T1();
        else
        {
            int item = stream.get();
            while (item != -1)
            {
                if (item != ' ' && item != '\t')
                    return T1();
                item = stream.get();
            }
        }
        return T1(p1, p2, p3);
    }

    template<typename T1, typename T2>
    inline T1 parse_bind4(const std::string& _value)
    {
        T2 p1, p2, p3, p4;
        std::istringstream stream(_value);
        stream >> p1 >> p2 >> p3 >> p4;
        if (stream.fail())
            return T1();
        else
        {
            int item = stream.get();
            while (item != -1)
            {
                if (item != ' ' && item != '\t')
                    return T1();
                item = stream.get();
            }
        }
        return T1(p1, p2, p3, p4);
    }


    namespace templates
    {
        template<typename T>
        inline void split(std::vector<std::string>& _ret, const std::string& _source, const std::string& _delims)
        {
            if (_source == "")
            {
                return;
            }
            size_t start = 0;
            size_t end = _source.find(_delims);
            while (start != _source.npos)
            {
                if (end != _source.npos)
                    _ret.push_back(_source.substr(start, end - start));
                else
                {
                    _ret.push_back(_source.substr(start));
                    break;
                }
                start = end;
                if (start != _source.npos)
                {
                    start += _delims.size();
                }
                end = _source.find(_delims, start);
            }
        }
    } // namespace templates

    inline std::vector<std::string> split(const std::string& _source, const std::string& _delims = "\t\n ")
    {
        std::vector<std::string> result;
        templates::split<void>(result, _source, _delims);
        return result;
    }

    inline std::string standardise_path(const std::string& origin)
    {
        std::string path = origin;

        std::replace(path.begin(), path.end(), '\\', '/');
        return path;
    }

    inline bool start_with(const std::string& _source, const std::string& _value)
    {
        size_t count = _value.size();
        if (_source.size() < count)
            return false;
        for (size_t index = 0; index < count; ++index)
        {
            if (_source[index] != _value[index])
                return false;
        }
        return true;
    }

    inline bool end_with(const std::string& _source, const std::string& _value)
    {
        size_t count = _value.size();
        if (_source.size() < count)
            return false;
        size_t offset = _source.size() - count;
        for (size_t index = 0; index < count; ++index)
        {
            if (_source[index + offset] != _value[index])
                return false;
        }
        return true;
    }

}

#endif //__ZCE_STRING__
