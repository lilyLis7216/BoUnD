#include "FrameRate.h"
#include "DxLib.h"

FrameRate::FrameRate()
    :deltaTime(0)
    ,prevTime(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Update()
{
    // fps���ő�l���傫���Ȃ�Ȃ��悤�ɂ��鏈��
    WaitFrame();

    // �f���^�^�C���̌v�Z
    deltaTime = (GetNowCount() - prevTime) / 1000.0f;

    // �f���^�^�C���𐧌�
    if (deltaTime >= 0.10f)
    {
        // �f���^�^�C����0.10f�ɐݒ肷��
        deltaTime = 0.10f;
    }

    // �O�t���[���Ƃ��Ă����܂ł����������Ԃ�ۑ�����
    prevTime = GetNowCount();
}

void FrameRate::WaitFrame()
{
    // ���ݒn��1�t���[���ɂ����鎞�Ԃ𒴂���܂ŌJ��Ԃ�
    while (GetNowCount() < prevTime + oneFrameTickCount);
}
