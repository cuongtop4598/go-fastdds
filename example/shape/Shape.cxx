// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file Shape.cpp
 * This source file contains the implementation of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "Shape.h"

#include <fastcdr/Cdr.h>


#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>




Shape::Shape()
{
}

Shape::~Shape()
{
}

Shape::Shape(
        const Shape& x)
{
    m_color = x.m_color;
    m_position_x = x.m_position_x;
    m_position_y = x.m_position_y;
}

Shape::Shape(
        Shape&& x) noexcept
{
    m_color = std::move(x.m_color);
    m_position_x = x.m_position_x;
    m_position_y = x.m_position_y;
}

Shape& Shape::operator =(
        const Shape& x)
{

    m_color = x.m_color;
    m_position_x = x.m_position_x;
    m_position_y = x.m_position_y;
    return *this;
}

Shape& Shape::operator =(
        Shape&& x) noexcept
{

    m_color = std::move(x.m_color);
    m_position_x = x.m_position_x;
    m_position_y = x.m_position_y;
    return *this;
}

bool Shape::operator ==(
        const Shape& x) const
{
    return (m_color == x.m_color &&
           m_position_x == x.m_position_x &&
           m_position_y == x.m_position_y);
}

bool Shape::operator !=(
        const Shape& x) const
{
    return !(*this == x);
}

/*!
 * @brief This function copies the value in member color
 * @param _color New value to be copied in member color
 */
void Shape::color(
        const std::string& _color)
{
    m_color = _color;
}

/*!
 * @brief This function moves the value in member color
 * @param _color New value to be moved in member color
 */
void Shape::color(
        std::string&& _color)
{
    m_color = std::move(_color);
}

/*!
 * @brief This function returns a constant reference to member color
 * @return Constant reference to member color
 */
const std::string& Shape::color() const
{
    return m_color;
}

/*!
 * @brief This function returns a reference to member color
 * @return Reference to member color
 */
std::string& Shape::color()
{
    return m_color;
}


/*!
 * @brief This function sets a value in member position_x
 * @param _position_x New value for member position_x
 */
void Shape::position_x(
        int32_t _position_x)
{
    m_position_x = _position_x;
}

/*!
 * @brief This function returns the value of member position_x
 * @return Value of member position_x
 */
int32_t Shape::position_x() const
{
    return m_position_x;
}

/*!
 * @brief This function returns a reference to member position_x
 * @return Reference to member position_x
 */
int32_t& Shape::position_x()
{
    return m_position_x;
}


/*!
 * @brief This function sets a value in member position_y
 * @param _position_y New value for member position_y
 */
void Shape::position_y(
        int32_t _position_y)
{
    m_position_y = _position_y;
}

/*!
 * @brief This function returns the value of member position_y
 * @return Value of member position_y
 */
int32_t Shape::position_y() const
{
    return m_position_y;
}

/*!
 * @brief This function returns a reference to member position_y
 * @return Reference to member position_y
 */
int32_t& Shape::position_y()
{
    return m_position_y;
}


// Include auxiliary functions like for serializing/deserializing.
#include "ShapeCdrAux.ipp"
