#pragma once

/**
* UserInterface
* UI管理クラス
*/
class UserInterface
{
public:
    /**
    * UserInterfaceのデストラクタ
    */
    ~UserInterface();

    /**
    * UserInterfaceのインスタンスの生成
    */
    static void CreateInstance();

    /**
    * UserInterfaceのインスタンスの削除
    */
    static void DeleteInstance();

    /**
    * テキスト（数値あり）
    * 
    * @param[in] x      x座標
    * @param[in] y      y座標
    * @param[in] color  表示色
    * @param[in] str    表示文字列
    * @param[in] num    表示数値
    */
    static void UIText(int x, int y, int color, const char* str, int num);

    /**
    * テキスト（数値なし）
    * 
    * @param[in] x      x座標
    * @param[in] y      y座標
    * @param[in] color  表示色
    * @param[in] str    表示文字列
    */
    static void UIText(int x, int y, int color, const char* str);

    /**
    * 枠生成
    * 
    * @param[in] x1         左上のx座標
    * @param[in] x2         右下のx座標
    * @param[in] y1         左上のy座標
    * @param[in] y2         右下のy座標
    * @param[in] frameSize  枠線の太さ
    * @param[in] mainCr     塗り潰す色
    * @param[in] frameCr    枠の色
    */
    static void UIBox(int x1, int x2, int y1, int y2, int frameSize, int mainCr, int frameCr);

private:
    /**
    * UserInterfaceのコンストラクタ
    * シングルトン
    */
    UserInterface();

    /** UserInterfaceのインスタンス*/
    static UserInterface* instance;
};