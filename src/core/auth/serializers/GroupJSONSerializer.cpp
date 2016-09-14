/*
    Copyright (C) 2014-2016 Islog

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

#include "core/auth/Group.hpp"
#include "GroupJSONSerializer.hpp"

using namespace Leosac;
using namespace Leosac::Auth;

std::string GroupJSONSerializer::to_string(const Auth::Group &group)
{
    return to_object(group).dump(4);
}

json GroupJSONSerializer::to_object(const Auth::Group &group)
{
    json memberships = {};
    for (const auto &membership : group.user_memberships())
    {
        json group_info = {{"id", membership->id()},
                           {"type", "user-group-membership"}};
        memberships.push_back(group_info);
    }
    json serialized = {
        {"id", group.id()},
        {"type", "group"},
        {"attributes",
         {
             {"name", group.name()}, {"description", group.description()},
         }},
        {"relationships", {{"memberships", {{"data", memberships}}}}}};

    return serialized;
}
