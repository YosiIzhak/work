#pragma once  

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <istream>


namespace cpp
{


class Image
{

public:

    Image(size_t a_x, size_t a_y, std::string a_type, int a_colorScale);
	~Image();

	Image(Image&& a_source);//move cctor
     Image& operator=(Image&& a_source); //move assignment

    Image(Image const& a_source); //cctor
   Image& operator=(Image const& a_source);//assignment op

    void setPixelbright(size_t a_x, size_t a_y, int a_factor);
    void setPixel(size_t a_x, size_t a_y, int a_value);
    int getPixel(size_t a_x, size_t a_y)const;
    size_t getWidth()const;
    size_t getHeigth()const;
    size_t setWidth(size_t a_value);
    size_t setHeigth(size_t a_value);
    int getScale() const;
    std::string getType() const;
    bool operator==(Image const& a_source);

private:
    size_t m_width;
    size_t m_heigth;
    std::string m_type;
    int m_scaleOfBright;
    int* m_matrix; 
   
};

void brighten (Image& src, int a_factor);


Image& read (std::ifstream &inFile, Image& result);


Image save(Image& a_dest, std::ofstream &outFile);

}//namespace 

#include "./inl/image.hxx"




