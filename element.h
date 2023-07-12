#ifndef ELEMENT_H
#define ELEMENT_H


class element
{
public:
    element();
    const int getElementID();
    void setElementID(int new_element_id);

private:
    int element_id;
};

#endif