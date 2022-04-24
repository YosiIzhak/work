#ifndef  IMAEGE_HXX
#define  IMAEGE_HXX


#include <sstream>

namespace cpp
{

template<typename T>
Image<T>::Image(size_t a_x, size_t a_y, int a_scaleOfBright)
: m_x(a_x)
, m_y (a_y)
, m_scaleOfBright(a_scaleOfBright)
{
    std::cout << "ctor\n";
    m_matrix = new T*[a_x];
    for(size_t i = 0; i < a_x; ++i)
    {
        m_pixels[i] = new T[a_y];
    }
}

template<typename T>
Image<T>::Image(Image const& a_source)
: m_x(a_source.m_x)
, m_y (a_source.m_y)
, m_scaleOfBright(a_source.m_scaleOfBright)
{
    std::cout << "cctor\n";
    m_matrix = new T*[m_x];
    for(size_t i = 0; i < m_x; ++i)
    {
        m_matrix[i] = new T[m_y];
        std::copy(a_source.m_matrix[i], a_source.m_matrix[i] + m_y, m_matrix[i]);
    }
}

template<typename T>
Image<T>::Image(Image&& a_source)
: m_x(a_source.m_x)
, m_y (a_source.m_y)
, m_scaleOfBright(a_source.m_scaleOfBright)
, m_pixels(a_source.m_matrix)
{
    std::cout << "move cctor\n";
    a_source.m_matrix = nullptr;
    a_source.m_x = 0;
}

template<typename T>
Image<T>& Image<T>::operator=(Image<T> const& a_source)
{
    if(*this == a_source){return *this;}

    std::cout << "copy\n";

    T** temp = new T*[a_source.m_x];
    for(size_t i = 0; i < a_source.m_x; ++i)
    {
        temp[i] = new T[a_source.m_y];
        std::copy(a_source.m_matrix[i], a_source.m_matrix[i] + a_source.m_y, temp[i]);
    }

    for(size_t i = 0; i < m_x; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;

    m_x = a_source.m_x;
    m_y = a_source.m_y;
    m_scaleOfBright = a_source.m_scaleOfBright;
    m_matrix = temp;

    return *this;
}

template<typename T>
Image<T>& Image<T>::operator=(Image<T>&& a_source)
{
    if(*this == a_source){return *this;}

    std::cout << "move copy\n";

    for(size_t i = 0; i < m_x; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;

    m_x = a_source.m_x;
    m_y = a_source.m_y;
    m_scaleOfBright = a_source.m_scaleOfBright;
    m_matrix = a_source.m_matrix;
    a_source.m_matrix = nullptr;
    a_source.m_x = 0;

    return *this;
}

template<typename T>
Image<T>::~Image()
{
     std::cout << "dtor\n";
    for(size_t i = 0; i < m_x; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
} 



template<typename T>
T Image<T>::getPixel(size_t a_x, size_t a_y)const
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the image range" << "\n";
        return m_matrix[m_x - 1][m_y - 1];;
    }
    return m_matrix[a_x][a_y];
}

template<typename T>
void Image<T>::setPixel(size_t a_x, size_t a_y, T a_factor)
{
    if(a_x >= m_x || a_y >= m_y)
    {
        std::cout << "Error: Point outside the image range" << "\n";
        return;
    }
    if(getPixel(a_x, a_y) > a_factor)
    {
        m_matrix[a_x][a_y] = getPixel(a_x, a_y) - a_factor;
    }
    else
    {
         m_matrix[a_x][a_y] = 0;
    }
}

template<typename T>
size_t Image<T>::getX()const
{
    return m_x;
}

template<typename T>
int Image<T>::getScale() const
{
    return m_scaleOfBright;
}

template<typename T>
size_t Image<T>::getY()const
{
    return m_y;
}
template<typename T>
void brighten (Image<T>& src, int a_factor)
{
    for(size_t i = 0; i < m_x; ++i)
    {
        for(size_t j = 0; j < m_y; ++j)
        {
            src.setPixel(i, j, a_factor);
        }
    }
}

template<typename T>
Image<T>& read (std::ifstream &inFile, Image<T>& result)
{
    int x, y, scale;
    std::string type;
    int num;
    
    inFile >> type >> x >> y >> scale;
    result.m_x = x;
    result.m_y = y;

    while(inFile.good())
    {
        for(size_t i = 0; i < result.getY(); ++i)
        {
            for(size_t j = 0; j < result.getX(); ++j)
            {
                inFile >> num;
                result[j][i] << num;
            }
        }
    }
    return result;
}

template<typename T>
Image<T> save(Image<T>& a_src, std::ofstream &outFile)
{
    outFile << type;
    outFile << a_src.getX();
    outFile << a_src.getY();
    outFile << a_src.getScale();

    for(size_t i = 0; i < result.getY(); ++i)
        {
            for(size_t j = 0; j < result.getX(); ++j)
            {
                outFile << result[j][i];
            }
        }

}
// template<typename T>
// bool Image<T>::operator==(Image const& a_source)
// {
//     return m_pixels == a_source.m_pixels;
// }

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