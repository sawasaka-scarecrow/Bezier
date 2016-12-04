#pragma once

#include <Windows.h>
#include <gdiplus.h>
#include <memory>
#include "master/MasterData.hpp"

enum Anchor
{
	LEFT_TOP,
	TOP,
	RIGHT_TOP,
	LEFT,
	CENTER,
	RIGHT,
	LEFT_BOTTOM,
	BOTTOM,
	RIGHT_BOTTOM,
};

class Renderer
{
public :
	~Renderer();

	/*!
	 * @brief 初期化
	 */
	void Initialize(HDC hdc);

	/*!
	 * @brief 画面クリア
	 */
	void ClearScreen(const Gdiplus::Color& color);

	/*!
	 * @brief 塗りつぶし描画
	 */
	void FillRect(int x, int y, int w, int h, const Gdiplus::Color& color);

	/*!
	 * @brief 画像描画
	 */
	void DrawImage(Gdiplus::Bitmap* image, Anchor anchor, int x, int y);

	/*!
	 * @brief 画像描画
	 */
	void DrawImage(Gdiplus::Bitmap* image, Anchor anchor, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh, const Gdiplus::Color& color);

	/*!
	 * @brief 文字列描画
	 */
	void DrawString(const char* s, int x, int y, int size = 20, const Gdiplus::Color& color = Gdiplus::Color::White);

	/*!
	 * @brief 文字列描画
	 */
	void DrawString(Anchor anchor, int x, int y, int size, const Gdiplus::Color& color, const char* s, ...);

	/*!
	 * @brief 文字列描画
	 */
	void DrawString(Anchor anchor, int x, int y, int size, const Gdiplus::Color& color, const wchar_t* s, ...);

	/*!
	 * @brief インスタンス取得
	 */
	static Renderer* GetInstance() {
		static Renderer v;
		return &v;
	}

private :
	Renderer();

	Gdiplus::GdiplusStartupInput gpsi_;
	ULONG_PTR token_;
	std::shared_ptr<Gdiplus::Graphics> graphics_;
};
