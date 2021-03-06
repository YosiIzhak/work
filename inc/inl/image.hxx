#ifndef  IMAEGE_HXX
#define  IMAEGE_HXX


#include <sstream>

namespace cpp
{


Image::Image(size_t a_width, size_t a_heigth, std::string a_type, int a_scaleOfBright)
: m_width(a_width)
, m_heigth (a_heigth)
, m_type (a_type)
, m_scaleOfBright(a_scaleOfBright)
{
    std::cout << "ctor\n";
    m_matrix = new int[a_width * a_heigth];
    
}


Image::Image(Image const& a_source)
: m_width(a_source.m_width)
, m_heigth (a_source.m_heigth)
, m_type (a_source.m_type)
, m_scaleOfBright(a_source.m_scaleOfBright)
{
    std::cout << "cctor\n";
    m_matrix = new int[m_width * m_heigth];
    
       std::copy(a_source.m_matrix[0], a_source.m_matrix[m_width * m_heigth], m_matrix[0]);
    
}


Image::Image(Image&& a_source)
: m_width(a_source.m_width)
, m_heigth (a_source.m_heigth)
, m_type (a_source.m_type)
, m_scaleOfBright(a_source.m_scaleOfBright)
, m_matrix(a_source.m_matrix)
{
    std::cout << "move cctor\n";
    a_source.m_matrix = nullptr;
    a_source.m_width = 0;
    a_source.m_heigth = 0;
}


Image& Image::operator=(Image const& a_source)
{
    if(*this == a_source){return *this;}

    std::cout << "copy\n";

    int* temp = new int[a_source.m_width *a_source.m_heigth];
    
   
    std::copy(a_source.m_matrix[0], a_source.m_matrix[m_width * m_heigth], temp[0]);
        
    delete m_matrix;

    m_width = a_source.m_width;
    m_heigth = a_source.m_heigth;
    m_scaleOfBright = a_source.m_scaleOfBright;
    m_matrix = temp;

    return *this;
}


Image& Image::operator=(Image&& a_source)
{
    if(*this == a_source){return *this;}

    std::cout << "move copy\n";

    delete[] m_matrix;

    m_width = a_source.m_width;
    m_heigth = a_source.m_heigth;
    m_scaleOfBright = a_source.m_scaleOfBright;
    m_matrix = a_source.m_matrix;
    a_source.m_matrix = nullptr;
    a_source.m_width = 0;
    a_source.m_heigth = 0;
    return *this;
}


Image::~Image()
{
     std::cout << "dtor\n";
     delete[] m_matrix;
} 




int Image::getPixel(size_t a_x, size_t a_y) const
{
    if(a_x >= m_width || a_y >= m_heigth)
    {
        return 0;
    }
    
    return m_matrix[m_width * (a_y) + a_x];
}


void Image::setPixel(size_t a_x, size_t a_y, int a_value)
{
    if(a_x >= m_width || a_y >= m_heigth)
    {
       return;
    }
    
   m_matrix[m_width * (a_y) + a_x] = a_value;
}


void Image::setPixelbright(size_t a_x, size_t a_y, int a_factor)
{
    if(a_x >= m_width || a_y >= m_heigth)
    {
        return;
    }
    if (m_matrix[m_width * (a_y) + a_x] == 0)
    {
        return;
    }
    m_matrix[m_width * (a_y) + a_x] = getPixel(a_x, a_y) + a_factor;
}


size_t Image::getWidth()const
{
    return m_width;
}

std::string Image::getType() const
{
    return m_type;
}

int Image::getScale() const
{
    return m_scaleOfBright;
}


size_t Image::getHeigth()const
{
    return m_heigth;
}

void brighten (Image& a_src, int a_factor)
{
    for(size_t i = 0; i < a_src.getWidth(); ++i)
    {
        for(size_t j = 0; j < a_src.getHeigth(); ++j)
        {
            a_src.setPixelbright(i, j, a_factor);
        }
    }
}

static int calcAverage(Image& a_src, size_t a_i, size_t a_j)
{
    int sum =0;
    for(int a = 0; a < 2; a = a + a_src.getWidth())
    {
        for(int b = 0; b < 2; ++b)
        {
           sum += a_src.getPixel(a_i+ a, a_j+ b);
        }  
    }
    return sum/ 9;
}

void blur(Image& a_src)
{
    for(size_t i = 0; i < a_src.getHeigth()-2; i= i+3)
    {
        for(size_t j = 0; j < a_src.getWidth()-2; j= j+3)
        {
            int blur = calcAverage(a_src, j, i);
            for(int a = 0; a < 2; a = a + a_src.getWidth())
            {
                for(int b = 0; b < 2; ++b)
                {
                   a_src.setPixel(i+a, j+b, blur);
                }  
            }
        }
    }
}

void sharp(Image& a_src)
{
    int sharpMatrix[] = {0,-1,0,-1,5,-1,0,-1,0};

    for(size_t i = 0; i < a_src.getHeigth()-2; i= i+3)
    {
        for(size_t j = 0; j < a_src.getWidth()-2; j= j+3)
        {
            int count = 0;
            for(int a = 0; a < 2; a = a + a_src.getWidth())
            {
                for(int b = 0; b < 2; ++b)
                {
                   a_src.setPixelbright(i+a, j+b, sharpMatrix[count]);
                }  
            }
        }
    }
}

size_t Image::setWidth(size_t a_value)
{
    m_width = a_value;
}
    
size_t Image::setHeigth(size_t a_value)
{
    m_heigth = a_value;
}

Image& read (std::ifstream &inFile)
{
    int x, y, scale;
    std::string type;
    int num;
    
    inFile >> type >> x >> y >> scale;
    cpp::Image result(x, y, type, scale);
    
    while(inFile.good())
    {
        for(size_t i = 0; i < result.getHeigth(); ++i)
        {
            for(size_t j = 0; j < result.getWidth(); ++j)
            {
                inFile >> num;
                result.setPixel(j, i, num);
            }
        }
    }
    return result;
}


Image save(Image& a_src, std::ofstream &outFile)
{
    outFile << a_src.getType();
    outFile << a_src.getWidth();
    outFile << a_src.getHeigth();
    outFile << a_src.getScale();

    for(size_t i = 0; i < a_src.getHeigth(); ++i)
        {
            for(size_t j = 0; j < a_src.getWidth(); ++j)
            {
                outFile << a_src.getPixel(j, i) << " ";
            }
            outFile << std::endl;
        }

}

bool Image::operator==(Image const& a_source)
{
    return m_matrix == a_source.m_matrix;
}

// template<typename T>
// bool isExists(Image<T> const& a_image, T a_pixels)
// {
//     const size_t x = a_image.x();
//     const size_t y = a_image.y();

//     for(size_t i = 0 ; i < x; ++i)
//     {
//         for(size_t j = 0 ; j < y; ++j)
//         {
//             if(a_image.get(i, j) == a_pixels)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }


}// namespace cpp

#endif // IMAEGE_HXX