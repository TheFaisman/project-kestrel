#include "../std_lib_facilities.h"

#include <iostream>
#include <string>
#include <vector>
/*
    Grammar:

    Sentence:
        Noun Verb
        Sentence Conjugation Sentence

    Conjugation:
        "and"
        "or"
        "but"

    Noun:
        "birds"
        "fish"
        "C++"

    Verb:
        "rules"
        "fly"
        "swim"

*/

class String_Stream {
    private:
        bool is_full_{false};
        std::string buffer_{""};
    public:
        std::string GetString();
        void PutBack(const std::string& str);
};

String_Stream str_stream{};

std::string String_Stream::GetString() {
    if (this->is_full_) {
        this->is_full_ = false;
        return this->buffer_;
    }
    std::string str;
    std::cin >> str;
    return str;
}

void String_Stream::PutBack(const std::string& str) {
    if (this->is_full_) {
        error("String stream full.");
    }
    this->buffer_   = str;
    this->is_full_  = true;
}

bool Conjugation() {
    std::string conj = "";
    conj = str_stream.GetString();
    if (conj == "and" || conj == "or" || conj == "but") {
        return true;
    } else if (conj == "q" || conj == ".") {
        str_stream.PutBack(conj);
    }
    return false;
}

bool Noun() {
    std::string noun = "";
    noun = str_stream.GetString();
    if (noun == "birds" || noun == "fish" || noun == "C++") {
        return true;
    } else if (noun == "q" || noun == ".") {
        str_stream.PutBack(noun);
    }
    return false;
}

bool Verb() {
    std::string verb = "";
    verb = str_stream.GetString();
    if (verb == "rules" || verb == "fly" || verb == "swim") {
        return true;
    } else if (verb == "q" || verb == ".") {
        str_stream.PutBack(verb);
    }
    return false;
}

bool Sentence() {
    bool noun = Noun();
    bool verb = Verb();
    bool is_ok = (noun && verb);

    std::string next = str_stream.GetString();
    str_stream.PutBack(next);
    
    if (next == "." || next == "q") {
        return is_ok; // We're done
    }

    bool conj = Conjugation();
    bool sentence = Sentence();

    return is_ok && (conj && sentence);
}

int main() {
    bool is_ok = false;
    while (std::cin) {
        std::string next = str_stream.GetString();
        if (next == "q") break; // Quit the program
        if (next == ".") {
            if (is_ok) {
                std::cout << "OK" << std::endl;
            } else {
                std::cout << "Not OK" << std::endl;
            }
        } else {
            str_stream.PutBack(next);
        }
        is_ok = Sentence();
    }
    return 0;
}