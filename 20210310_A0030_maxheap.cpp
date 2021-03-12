
#include<iostream>
#include<fstream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1000000007
using namespace std;

int h[10001];
int N;

void insert(int n, int i) {
	if (i == 1) {
		h[i] = n;
		return;
	}
	h[i] = n;
	while(h[i / 2] < n){
		if (i == 1) break;
		swap(h[i / 2], h[i]);
		i /= 2;
	}
}


int pop() {
	int get = h[1];
	swap(h[1], h[N]);
	h[N] = 0;
	N--;
	int i = 1;
	while (h[i] < h[i * 2] || h[i] < h[i * 2 + 1]) {
		if (i * 2 > N) break;
		if (h[i * 2] > h[i * 2 + 1]) {
			swap(h[i], h[i * 2]);
			i = i * 2;
		}
		else {
			swap(h[i], h[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return i;
}


int main() {
	ifstream f("input.txt");
	int CA;
	f >> CA;
	for (int ca = 1; ca <= CA; ca++) {
		long long res = 0;
		f >> N;
		for (int i = 1; i <= N; i++) {
			int n;
			f >> n;
			insert(n, i);
		}

		int t = pop();
		int a = log2(t);
		int b = t - pow(2, a) + 1;

		printf("#%d %d %d\n", ca, a, b);

	}
	return 0;
}



========================


10
5
9 7 1 6 3
6
10 7 6 1 3 2
9
19 18 16 13 15 10 12 1 8
10
24 23 21 19 20 18 16 11 14 10
50
99 92 95 77 89 83 91 48 71 86 81 73 68 85 76 26 32 49 66 53 80 61 67 70 21 40 50 3 1 4 20 19 14 24 6 30 39 56 52 7 46 27 75 13 44 36 25 62 22 5
100
493 487 476 469 467 470 472 406 441 437 442 458 435 397 459 401 390 426 253 258 415 385 335 412 316 276 348 325 346 347 349 298 244 233 379 404 260 147 68 215 248 229 235 144 369 311 82 350 384 221 35 46 57 74 29 39 214 143 145 203 32 303 80 175 102 225 17 117 27 297 130 312 388 184 199 85 128 61 54 37 53 101 178 172 159 122 13 8 67 86 113 222 141 51 12 136 137 223 243 40
1000
9998 9967 9962 9949 9931 9904 9933 9758 9928 9909 9819 9887 9834 9682 9872 9748 9683 9821 9418 9813 9756 9579 9591 9484 9878 9645 9666 9511 9599 9690 9858 9462 9687 8617 9469 9654 8930 8428 9234 9361 9516 9570 9200 9403 8403 9400 8818 9386 8938 9836 9375 9573 9636 9491 9489 8486 9097 9261 9276 9344 9153 9786 9637 8095 8799 9397 9022 8294 7653 9466 9301 8339 6940 8315 8629 7245 7802 8261 8524 9282 9179 8939 9428 6888 8462 8973 8877 9018 8990 8382 8324 9398 9390 7733 8379 9317 8126 8675 7551 9117 9181 8992 8602 9495 9348 8863 9537 8508 8027 8562 8842 8422 7442 8823 8926 9131 8526 8321 9269 7968 8866 7952 8372 9408 8912 7445 9033 7212 7133 7755 7971 7129 7893 7854 7767 6803 6618 6083 7512 8647 9008 8558 8309 8112 8208 6911 5907 8070 7882 7630 6795 7202 6984 6317 7229 5899 7356 7139 8161 8415 8358 8402 8721 8410 7194 8449 5996 4954 6305 8140 7922 8471 8030 7433 8751 8908 6456 6772 8659 6548 8069 8303 6094 8649 8701 8924 8907 7524 4599 8249 7521 7993 9038 7892 7897 8194 8622 7530 4749 5502 7866 6866 6053 8167 7730 8353 7044 9255 9034 8826 8142 8086 8193 7033 7196 7969 6555 7914 7239 8118 7749 6513 7262 8179 7089 6530 6309 7168 7103 7569 7557 8738 8601 7350 8470 7724 6825 9232 7154 6851 7785 8286 5842 7132 6903 7502 5320 7603 9156 7974 8420 5880 5965 5685 3184 5302 5981 7045 4479 6840 6977 4544 4090 2202 6464 7018 4733 4904 7340 3836 6878 5217 6660 6512 4775 5204 5864 4337 5572 6890 8400 8407 8024 6204 6404 2515 6714 7443 2341 6069 4636 1959 4675 4930 5494 7736 4304 5648 6705 7436 4495 6776 5071 7034 5967 5850 6572 2059 1255 5990 4412 2433 3250 6635 5759 6510 6082 3857 4734 7466 4147 8003 5610 6425 7710 5853 8714 7213 5606 6272 6267 7525 3301 5615 5690 4131 2501 5710 4640 6841 8028 6732 7475 7913 8174 5517 4707 7419 3241 3407 5298 1968 7523 5946 5765 5511 4922 8584 6913 3746 6469 5193 7871 6872 5384 4822 3284 8348 6769 7990 8364 8811 8652 6876 8157 5555 3891 4360 3594 6158 4710 6862 5027 7903 7979 8963 8413 5881 6491 4557 6788 4812 3417 5343 3504 6994 7529 4494 3556 2552 5406 5387 7012 4589 6092 5044 2774 7190 4817 4540 7577 5980 5888 6604 7014 5056 7046 6964 7581 6368 7558 2242 7594 7989 3530 7147 7902 4208 3065 6780 6337 7007 4851 5143 4217 7023 7062 7178 6303 6342 4374 2568 5393 6195 5936 4810 6690 7244 7489 4375 6586 5540 4257 3789 4984 5250 2698 6232 2581 7019 6887 3735 6734 5100 8691 7159 8029 6055 7281 3185 6673 7277 6123 3759 3903 8713 7765 6671 6316 4388 6351 5733 6815 6534 6027 4104 3183 5971 6775 6105 6327 6831 5275 3033 4618 7343 1700 6435 8530 3268 6096 26 1992 876 433 53 2673 5000 5421 373 1219 4387 2605 1295 2465 6421 3315 493 2230 2401 954 5271 5903 4402 1713 685 1688 947 350 3863 2469 6616 4774 4307 4210 221 3361 5656 4511 2813 1006 1537 5941 3286 1980 2015 5954 4538 1922 242 392 2180 2495 5535 1777 1273 120 3605 287 3189 462 6471 7175 7361 5274 364 1208 4209 4965 4325 4576 1097 1639 3001 529 4813 4688 345 154 993 1750 2887 1881 873 912 3615 4392 3101 3792 2608 3501 3590 1974 3060 1686 4258 3632 2434 5226 1955 2264 3314 3975 1223 352 4800 4837 2800 2029 3571 4953 4814 2480 6093 5958 2035 1888 1157 1158 4755 3483 1456 2646 1009 1410 1129 1315 3500 4305 2101 2814 369 1445 168 5118 47 2683 3714 3859 6466 5841 3964 2538 1634 2063 3308 215 1457 4821 2399 4116 1024 5212 4516 1963 1169 1693 3383 668 224 231 3130 3021 3110 479 2961 767 3977 3527 3883 666 928 3174 730 243 857 5637 1574 2938 370 3694 1249 3506 593 1772 2387 6405 3705 749 4765 7413 2907 5257 1459 66 704 1894 295 2150 1882 2221 2484 5017 1520 517 6398 1764 3573 1239 219 4345 5439 616 906 3017 7192 2669 5425 6444 1330 3011 2598 2657 2677 3934 699 7781 5339 4764 810 260 3544 43 2557 603 7048 958 3695 1384 2358 5863 5480 2211 5963 6754 4949 2691 6868 1551 3267 4394 5396 1916 2067 129 4358 4296 1523 51 2624 4566 3526 4534 6816 290 3795 3063 1900 2010 6283 5415 5776 385 8356 317 1741 4368 645 1684 700 4385 5879 3854 2889 4633 750 1188 4923 3371 2114 991 3650 4148 3488 3683 307 3725 3325 2498 2438 2390 1382 883 2308 1469 530 3145 3492 4122 2292 5783 1251 139 114 1573 763 5533 1337 4009 2200 2574 4983 5554 1620 471 3618 3768 6164 2479 3446 1444 417 643 6590 3204 3538 5045 3048 4577 3663 4651 3793 3369 2003 832 5091 3385 2192 5030 2997 1865 559 5635 955 5552 3988 36 2126 2089 1666 5549 2604 5784 6856 3187 4619 2463 4294 264 1751 2838 885 5213 4438 1478 6546 5839 5088 1812 727 3932 3409 147 1308 241 4873 1662 5219 1622 2785 1452 1729 3833 5353 3568 4496 3427 366 6588 1000 525 2125 3895 1897 935 2965 1248 2616 429 330 48 1030 2794 1644 657 5789 1562 1495 1635 2248 5435 416 2636 3324 2626 4314 1553 4448 245 5182 4052 7058 2845 3481 6430 4679 2772 2745 4435 2466 1771 1120 6222 6332 459 5431 1706 506 222 3892 1690 6797 5138 2894 7588 1546 6374 3582 548 751 2244 3169 875 2953 4806 4348 1115 5389 2867 2849 4906 2641 209 2151 2322 2711 5239 230 1631 2328 1338 675 4003 3372 6538 2517 377 1596 874 974 2338 1198 987 736 1235 773 1736 5703 6074 3186