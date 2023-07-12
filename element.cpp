#include "element.h"
#include <iostream>


element::element()
{

}

const int element::getElementID()
{
    return element_id;
}

void element::setElementID(int new_element_id)
{
    this->element_id = new_element_id;
}