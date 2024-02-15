#include "Sprite.h"

bool Sprite::Create(const std::string& filename)
{
	if (!HAPI.LoadTexture(filename, &m_texture, m_tWidth, m_tHeight))
	{
		HAPI.UserMessage("Data sucks", "Data sucks good");
		return false;
	}
	return true;
}

void Sprite::TransDraw(BYTE* screen, RectangleC screenRC, int sX, int sY)
{
	RectangleC textRect(0, m_tWidth, 0, m_tHeight);

	textRect.Translate(sX, sY);
	textRect.Clip(screenRC);
	textRect.Translate(-sX, -sY);

	if (sY < 0)
		sY = 0;
	if (sX < 0)
		sX = 0;


	int ScreenOffset = (sY * screenRC.Width() + sX) * 4;
	int TextOffset = (textRect.top * m_tWidth + textRect.left) * 4;

	int EndofScreenOffset = (screenRC.Width() - textRect.Width()) * 4;
	int EndofTextureOffset = (m_tWidth - textRect.Width()) * 4;

	for (int y = 0; y < textRect.Height(); y++)
	{
		for (int x = 0; x < textRect.Width(); x++)
		{
			BYTE sa = m_texture[TextOffset + 3];
			if (sa != 0)
			{
				if (sa == 255)
				{
					memcpy(screen + ScreenOffset, m_texture + TextOffset, 4);
				}
				else{
					BYTE Blue = m_texture[TextOffset];
					BYTE Green = m_texture[TextOffset + 1];
					BYTE Red = m_texture[TextOffset + 2];


					screen[ScreenOffset] = screen[ScreenOffset] + ((sa * (Blue - screen[ScreenOffset])) >> 8);
					screen[ScreenOffset + 1] = screen[ScreenOffset + 1] + ((sa * (Green - screen[ScreenOffset + 1])) >> 8);
					screen[ScreenOffset + 2] = screen[ScreenOffset + 2] + ((sa * (Red - screen[ScreenOffset + 2])) >> 8);
				}
			}

			ScreenOffset += 4;
			TextOffset += 4;
		}
		ScreenOffset += EndofScreenOffset;
		TextOffset += EndofTextureOffset;
	}
}

Sprite::~Sprite()
{
	delete[](this->m_texture);
}




























//void Sprite::TransDraw(BYTE* screen, RectangleC screenRC, int sX, int sY, int frameNum)
//{
//			TxtPointer = text;
//			ScreenPointer = Screen;
//			ScreenOffset = (xPos + yPos * m_Width) * 4;
//			TxtOffset = 0;
//		
//			int EndOFLineScreenIncrement = (sWidth - tWidth) * 4;
//		
//			for (int y = 0; y < tHeight; y++)
//			{
//				for (int x = 0; x < tWidth; x++)
//				{
//					BYTE sa = TxtPointer[TxtOffset + 3];
//					if (sa != 0)
//					{
//						BYTE Blue = TxtPointer[TxtOffset];
//						BYTE Green = TxtPointer[TxtOffset + 1];
//						BYTE Red = TxtPointer[TxtOffset + 2];
//		
//						float Mod = sa / 255.0f;
//		
//						ScreenPointer[ScreenOffset] = ScreenPointer[ScreenOffset] + ((sa * (Blue - ScreenPointer[ScreenOffset])) >> 8);
//						ScreenPointer[ScreenOffset + 1] = ScreenPointer[ScreenOffset + 1] + ((sa * (Green - ScreenPointer[ScreenOffset + 1])) >> 8);
//						ScreenPointer[ScreenOffset + 2] = ScreenPointer[ScreenOffset + 2] + ((sa * (Red - ScreenPointer[ScreenOffset + 2])) >> 8);
//					}
//					ScreenOffset += 4;
//					TxtOffset += 4;
//				}
//				ScreenPointer += EndOFLineScreenIncrement;
//			}
//
//}

//void Sprite::Draw(BYTE* screen, RectangleC screenRC, int sX, int sY)
//{
//	TxtPointer = m_texture;
//	ScreenPointer = screen + (sX + sY * sWidth) * 4;
//	RectangleC textRect(0, m_tWidth, 0, m_tHeight);
//
//	textRect.Translate(sX, sY);
//	textRect.Clip(screenRC);
//	textRect.Translate(-sX, -sY);
//
//	if (sY < 0)
//		sY = 0;
//	if (sX < 0)
//		sX = 0;
//
//	for (int y = 0; y < m_tHeight; y++)
//	{
//		memcpy(ScreenPointer, TxtPointer, m_tWidth * 4);
//
//		TxtPointer += m_tWidth * 4;
//		ScreenPointer += sWidth * 4;
//	}
//}