/*
 * copyright (c) 2015 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of jni4android.
 *
 * jni4android is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * jni4android is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with jni4android; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "ast_node.hpp"
#include "ast_compilation_unit.hpp"
#include "ast__context.hpp"

using namespace ast;

void Node::init(Node *other)
{
    if (other) {
        set_parent(other->get_parent());
    } else {
        set_parent(NULL);
    }
}

void Node::put_in_pool()
{
    Context::instance()->put(this);
}

Method *Node::get_this_method()
{
    if (!get_parent())
        return NULL;

    return get_parent()->get_this_method();
}

CompilationUnit *Node::get_this_compilation_unit()
{
    if (!get_parent())
        return NULL;

    return get_parent()->get_this_compilation_unit();
}

Class *Node::get_this_class()
{
    if (!get_parent())
        return NULL;

    return get_parent()->get_this_class();
}

Identifier *Node::get_this_package()
{
    if (!get_this_compilation_unit())
        return NULL;

    return get_this_compilation_unit()->get_package();
}
