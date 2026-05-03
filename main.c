/* 
  파일이름: main.c
  작 성 자: 김영웅, 2026-04-05
  하 는 일: 나만의 맞춤형 카페 키오스크 주문 시스템
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  system("chcp 65001");
  // 변수 선언
  int menu_choice, count, money_in;
  int price = 0;
  int total_price, change;
  //1. 메뉴판 출력
  printf("---CAFE KIOSK ---\n");
  printf("1. 아메리카노 (2500원)\n");
  printf("2. 카페라떼 (3000원)\n");
  printf("메뉴 번호를 선택하세요: ");
  scanf("%d", &menu_choice);

//2. 메뉴 선택
  if(menu_choice == 1)
  {
    price = 2500;
    printf("아메리카노를 선택하셨습니다.\n");
  }
  else if(menu_choice == 2)
  {
    price = 3000;
    printf("카페라떼를 선택하셨습니다.\n");
  }
  else
  {
    printf("없는 메뉴입니다. 주문을 종료합니다.\n");
    return 0;
  }

  //3. 수량 입력 및 총액 계산
  printf("수량을 입력하세요 (최대 100잔): ");
  scanf("%d", &count);

  if(count>=1 && count<=100)
  {
    total_price = price * count;
    printf("총 결제 금액은 %d원입니다.\n", total_price);

    //4. 결제 및 잔돈 계산
    printf("돈을 투입해주세요: ");
    scanf("%d", &money_in);

    if(money_in >= total_price)
    {
      change = money_in - total_price;
      printf("결제가 완료되었습니다.\n");
      printf("거스름돈은 %d원입니다. 감사합니다. \n", change);

      //5. 영수증 출력
      printf("--------------------\n");
      printf("합계 금액: %d원\n", total_price);
      printf("받은 금액: %d원\n", money_in);
      printf("거스름돈: %d원\n", change);
      printf("********************\n");
      printf("이용해주셔서 감사합니다!\n");
    }

    else
    {
      printf("잔액이 %d원 부족합니다. 주문이 취소되었습니다.\n", total_price - money_in);
    }
  }  
  else
  {
    printf("수량은 1잔에서 100잔 사이만 주문 가능합니다.\n");
  }  
  return 0;
}
