#include "Game.hpp"


// TODO: 砲台の位置を画面左に、ターゲットの位置を画面右に移動させる。(A)
// TODO: 雲の位置を左から右に動かす。見えなくなったら左端に戻す。(B)
// TODO: 砲台を青い壁に沿って上下に動かす。(C)
// TODO: 弾のスピードを速くし、弾が画面右端を通り越したら再度発射可能にする。(D)
// TODO: スコアのサイズを大きくする。(E)
// TODO: スコアを100点ずつ加算するようにし、5桁の表示に変える。(F)
// TODO: PlayBGM()関数を使って、BGMを再生する。(G)
// TODO: PlaySE()関数を使って、弾の発射時とターゲットに当たった時にSEを再生する。(H)


Vector2 cloudPos;       //!< 雲の位置
Vector2 cannonPos;      //!< 砲台の位置
Vector2 bulletPos;      //!< 弾の位置
Rect    targetRect;     //!< ターゲットの矩形
int     score;          //!< スコア


// ゲーム開始時に呼ばれる関数です。
void Start()
{
    cloudPos = Vector2(-320, 100);
    cannonPos = Vector2(-304, -150);
    targetRect = Rect(280, -140, 40, 40);
    bulletPos.x = -999;
    score = 0;
    PlayBGM("bgm_maoudamashii_8bit07.mp3");//BGMを再生　HW16A184松本丈一郎
}

// 1/60秒ごとに呼ばれる関数です。モデルの更新と画面の描画を行います。
void Update()
{
    // 弾の発射
    if (bulletPos.x <= -999 && Input::GetKeyDown(KeyMask::Space)) {
        bulletPos = cannonPos + Vector2(50, 10);
        PlaySound("se_maoudamashii_explosion03.mp3");
    }

    // 弾の移動
    if (bulletPos.x > -999) {
        bulletPos.x += 1000 * Time::deltaTime;

        // ターゲットと弾の当たり判定
        Rect bulletRect(bulletPos, Vector2(32, 20));
        if (targetRect.Overlaps(bulletRect)) {
            score += 100;         // スコアの加算を３桁に変更　HW16A184松本丈一郎
            bulletPos.x = -999; // 弾を発射可能な状態に戻す
<<<<<<< HEAD
            PlaySound("se_maoudamashii_system27.mp3");//SEを再生する（実装：HW16A146　長杉星弥）
=======
            
            if(bulletPos.x > 320){
                bulletPos.x = -500;
            }
>>>>>>> 4c19797d6e7dd3d5a078b2d58c649d7b292ec413
        }
    }

    // 背景の描画
    Clear(Color::cyan);
    FillRect(Rect(-320, -240, 640, 100), Color::green);

    // 雲の描画
    DrawImage("cloud1.png", cloudPos);
<<<<<<< HEAD
    cloudPos.x += 3;          //雲を動かす（実装：HW16A146　長杉星弥）
    if(cloudPos.x >320){
        cloudPos.x = -500;
    }
=======
    cloudPos.x += 3;
    if(cloudPos.x > 320){ //弾のリロード　hw16a166 藤原　渉
        cloudPos.x = -500;
    }

>>>>>>> 4c19797d6e7dd3d5a078b2d58c649d7b292ec413

    // 弾の描画
    if (bulletPos.x > -999) {
        DrawImage("bullet.png", bulletPos);
    }

    // 砲台の描画
    FillRect(Rect(cannonPos.x-16, -140, 20, 100), Color::blue);//砲台の位置を変更　HW16A166　藤原　渉
    DrawImage("cannon.png", cannonPos);

    // ターゲットの描画
    FillRect(targetRect, Color::red);

    // スコアの描画
    SetFont("nicoca_v1.ttf", 70.0f);//スコアのサイズを大きくする（実装：HW16A146　長杉星弥）
    DrawText(FormatString("%02d", score), Vector2(-319, 150), Color::black);
    DrawText(FormatString("%02d", score), Vector2(-320, 151), Color::white);
}

