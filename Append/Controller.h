#pragma once

/**
* Controllerクラス
*/
class Controller
{
public:
    /**
    * コントローラーのコンストラクタ
    */
    ~Controller();

    /**
    * コントローラーのインスタンス生成
    */
    static void CreateInstance();

    /**
    * コントローラーのインスタンス削除
    */
    static void DeleteInstance();

    /**
    * コントローラーの更新
    */
    static void Update();

    /**
    * 左入力の取得
    */
    static bool LeftInput() { return leftInput; }

    /**
    * 右入力の取得
    */
    static bool RightInput() { return rightInput; }

    /**
    * スタートボタン入力の取得
    */
    static bool StartInput() { return startInput; }

    /**
    * Xボタン入力の取得
    */
    static bool XInput() { return xInput; }

    /**
    * バックボタン入力の取得
    */
    static bool BackInput() { return backInput; }

private:
    /**
    * コントローラーのコンストラクタ
    */
    Controller();

    /** コントローラーの実体*/
    static Controller* instance;

    /** コントローラーの入力状態*/
    static int padState;

    /** 左入力*/
    static bool leftInput;

    /** 右入力*/
    static bool rightInput;

    /** スタートボタン入力*/
    static bool startInput;

    /** Xボタン入力*/
    static bool xInput;

    /** バックボタン入力*/
    static bool backInput;
};