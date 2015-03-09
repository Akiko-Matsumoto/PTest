#include "stdafx.h"
#include "opencv_lib.hpp"								// OpenCV�w�b�_

int _tmain(int argc, _TCHAR* argv[])
{
	Mat frame;											// �摜���\�[�X�錾
	VideoCapture src(1);								// �f���擾�i�J�����f���j
	if (src.isOpened() == 0){ cout << "�f�����擾�ł��܂���B\n" << endl; waitKey(0); return -1;}

	while (frame.data == NULL){ src >> frame; }			// �����t���[���擾

	int w = frame.cols, h = frame.rows;					// �f���t���[���̕��ƍ���

	while (1){

		src >> frame; if (frame.data == NULL) break;	// 1�t���[���擾
		//���S���W��RGB�l�\���i�ϊ��O�j
		printf("RGB=(%3d, %3d, %3d) �� ", Ri(frame, w / 2, h / 2),
				Gi(frame, w / 2, h / 2), Bi(frame, w / 2, h / 2));

		for (int y = h / 3; y < h * 2 / 3; y++){		//�s�N�Z���l�ϊ��̈搂������
			for (int x = w / 3; x < w * 2 / 3; x++){	//�s�N�Z���l�ϊ��̈搅������
				if (Ri(frame, x, y) > 200){				//�Ԃ̃s�N�Z���l��200���傫���ꍇ
					Ri(frame, x, y) = 255;
					Gi(frame, x, y) = 255;
					Bi(frame, x, y) = 255;
				}
				else{									//�Ԃ̃s�N�Z���l��200�ȉ��̏ꍇ
					Ri(frame, x, y) = 0;
					Gi(frame, x, y) = 0;
					Bi(frame, x, y) = 0;
				}
			}
		}
		//���S���W��RGB�l�\���i�ϊ���j
		printf("RGB=(%3d, %3d, %3d)\n", Ri(frame, w / 2, h / 2),
				Gi(frame, w / 2, h / 2), Bi(frame, w / 2, h / 2));

		imshow("���͉f��", frame);						// 1�t���[���\��

		if(waitKey(30) == 27) break;					// �L�[���͑ҋ@�i30ms�j
	}

	return 0;
}
