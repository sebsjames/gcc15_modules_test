module;

#include <has_tools.h> // not ok if tools is in this #included file and comes before nlohmann
#include <nlohmann/json.hpp>
// #include <has_tools.h> // ok if #included AFTER nlohmann json

export module test1;

// import mplot.tools; // ok if imported here

export namespace test
{
    class tt
    {
    public:
        tt() { this->init(); }
        ~tt() {}
        float get_value() const { return this->value; }
    protected:
        void init() { this->value = 2.0f; }
        float value = 0.0f;
    };
}
