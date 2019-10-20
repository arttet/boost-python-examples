#pragma once

#include <string>

struct base_t final
{
    explicit base_t()
       : name_("Base")
    {
    }

    explicit base_t(std::string const& name)
       : name_(name)
    {
    }

    std::string name() const
    {
       return name_;
    }

private:
    std::string name_;
};
