/*
    Copyright (C) 2014-2017 Leosac

    This file is part of Leosac.

    Leosac is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Leosac is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "hardware/HardwareFwd.hpp"
#include <cstdint>
#include <odb/core.hxx>
#include <string>

namespace Leosac
{
namespace Hardware
{

/**
 *  Abstraction of a GPIO object property.
 *
 *  Modules that provides GPIO support may subclass
 *  this to provide additional settings.
 */
#pragma db object optimistic polymorphic
class GPIO
{
  public:
    explicit GPIO();
    virtual ~GPIO() = default;

    const std::string &name() const;

    void name(const std::string &name);

    GPIOId id() const;

    uint64_t version() const;

  private:
    std::string name_;

#pragma db id auto
    GPIOId id_;

#pragma db version
    uint64_t version_;

    friend odb::access;
};
}
}
