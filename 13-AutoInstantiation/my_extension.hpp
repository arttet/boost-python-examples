#pragma once

#include <string>

struct base_t final
{
   explicit base_t()
      : name_("Base")
   {
   }

   explicit base_t(std::string name)
      : name_(std::move(name))
   {
   }

   std::string name() const
   {
      return name_;
   }

private:
   std::string name_;
};
