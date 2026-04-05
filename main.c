/* 
  파일이름: main.c
  작 성 자: 김영웅, 2026-04-05
  하 는 일: 나만의 맞춤형 카페 키오스크 주문 및 매출 관리 시스템
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("chcp 65001");
// 변수 선언
char initial; // 고객 이니셜 1글자
int americano_qty; // 아메리카노 수량
int latte_qty; // 라떼 수량
int subtotal; // 세금 포함 전 금액
double vat; // 부가세 (소수점 계산을 위해 double 사용)
double total; // 최종 결제 금액

// 1. 각 메뉴의 고정 가격
int americano_price = 3000;
int latte_price = 4000;

// 2. 카페 메뉴판 출력
printf("===환영합니다~ 웅이네 카페입니다!===\n");
printf("1. 아메리카노 : %d원\n", americano_price);
printf("2. 카페라떼 : %d원\n", latte_price);
printf("=================================\n");

// 3. 주문 정보 및 이니셜 입력
printf("고객의 이니셜(영문 1글자)을 입력해주세요: ");
scanf("%c", &initial);

printf("아메리카노의 주문 수량을 입력해주세요: ");
scanf("%d", &americano_qty);

printf("라떼의 주문 수량을 입력해주세요: ");
scanf("%d", &latte_qty);

// 4. 금액 및 부가세 계산
subtotal = (americano_price * americano_qty) + (latte_price * latte_qty);
//부가세 10% 계산
vat = subtotal * 0.1;
//최종 금액 계산
total = subtotal + vat;

//5. 영수증 출력 
printf("\n==========영수증==========\n");
printf("고객 진동벨 이니셜: %c\n", initial);
printf("_________________________\n");
printf("아메리카노: %d잔\n", americano_qty);
printf("라떼: %d잔\n", latte_qty);
printf("_________________________\n");
printf("주문 합계 : %d원\n", subtotal);
printf("부가세(10%%): %.0f원\n", vat);
printf("최종 결제 금액: %.0f원\n",total);
printf("========================\n");

return 0;
}
