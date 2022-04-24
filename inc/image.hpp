#pragma once  

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <istream>


namespace cpp
{

template <typename T>
class Image
{

public:

    Image(size_t a_x, size_t a_y, int a_colorScale);
	~Image();

	Image(Image&& a_source);//move cctor
     Image<T>& operator=(Image<T>&& a_source); //move assignment

    Image(Image const& a_source); //cctor
   Image<T>& operator=(Image<T> const& a_source);//assignment op

    void setPixel(size_t a_x, size_t a_y, T a_factor);
    T getPixel(size_t a_x, size_t a_y)const;
    size_t getX()const;
    size_t getY()const;
    int getScale() const;

private:
    size_t m_x;
    size_t m_y;
    int m_scaleOfBright;
    T** m_matrix; 
   
};
template <typename T>
void brighten (Image<T>& src, int a_factor);

template <typename T>
Image<T>& read (std::ifstream &inFile, Image<T>& result);

template <typename T>
Image<T> save(Image<T>& a_dest, std::ofstream &outFile);

}//namespace 

#include "./inl/image.hxx"




