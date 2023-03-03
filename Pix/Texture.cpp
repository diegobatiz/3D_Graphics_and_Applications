#include "Texture.h"

namespace
{
#pragma pack(push, 1)
	struct BitMapFileHeader
	{
		uint16_t type;           //magic identifier
		uint32_t size;			 //file size in bytes
		uint16_t reserved1;		 //
		uint16_t reserved2;		 //
		uint32_t offset;		 //byte offset to image data
	};

	struct BitMapInfoHeader
	{
		uint32_t size;					//header size in bytes
		int width, height;				//width and height of image
		uint16_t planes;				//number of color planes
		uint16_t bits;					//bits per pixel
		uint32_t compression;			//compression type
		uint32_t imageSize;				//image size in bytes
		int xResolution, yResolution;	//pixels per meter
		uint32_t numColors;				//number of colors
		uint32_t importantColors;		//important colors
	};
#pragma pack(pop)
}

void Texture::Load(const std::string& fileName)
{
	mFileName = fileName;

	FILE* file = nullptr;
	fopen_s(&file, fileName.c_str(), "rb");
	if (file == nullptr)
	{
		return;
	}
}

const std::string& Texture::GetFileName() const
{
	return mFileName;
}

X::Color Texture::GetPixel(float u, float v, AddressMode mode) const
{
	switch (mode)
	{
	case AddressMode::Border:
	{
		if (u > 1.0f || u < 0.0f || v > 1.0f || v < 0.0f)
		{
			return X::Colors::Pink;
		}
	}
	break;
	case AddressMode::Clamp:
	{
		u = std::clamp(u, 0.0f, 1.0f);
		v = std::clamp(v, 0.0f, 1.0f);
	}
	break;
	case AddressMode::Mirror:
	{
		while (u > 2.0f)
		{
			u -= 2.0f;
		}
		u = (u > 1.0f) ? (2.0f - u) : u;
		while (v > 2.0f)
		{
			v -= 2.0f;
		}
		v = (v > 1.0f) ? (2.0f - v) : v;
	}
	break;
	case AddressMode::Wrap:
	{
		while (u > 1.0f)
		{
			u -= 1.0f;
		}
		while (u < 0.0f)
		{
			u += 1.0f;
		}
		while (v > 1.0f)
		{
			v -= 1.0f;
		}
		while (v < 0.0f)
		{
			v += 1.0f;
		}
	}
	break;
	default:
		break;
	}

	int uIndex = static_cast<int>(u * (mWidth - 1));
	int vIndex = static_cast<int>(v * (mHeight - 1));
	return mPixels[uIndex + (vIndex * mWidth)];
}
