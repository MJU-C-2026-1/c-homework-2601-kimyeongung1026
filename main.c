/* 
  파일이름: main.c
  작 성 자: 김영웅, 2026-04-05
  하 는 일: 나만의 맞춤형 카페 키오스크 주문 시스템
*/
#include <stdio.h>
#include <stdlib.h>
// 영수증을 출력하는 함수
void printf_receipt(int cart[, int total, int moneym int change)
{
  printf("====== 영수증 ======\n")
  if (cart [0] > 0) printf("아메리카노: %d잔\n", cart[0]);
  if (cart [1] > 0) printf("카페라떼: %d잔\n", cart[1]);
  printf("--------------------\n");
  printf("최종 합계: %d원\n" , total);
  printf("받은 금액: %d원\n", money);
  printf("거스름돈 : %d원\n", change);
  printf("********************\n");
  printf("이용해주셔서 감사합니다!\n");
}

int calculate_distcount (int total_qty, int original_price)
{
  if (total_qty >= 5)
  {
    printf("\n 단골 감사 이벤트! 5잔 이상 구매로 10% 할인이 적용됩니다!!"\n");
    return original_price * 0.9;
  }
  return original_price;
}

int main()
{
  system("chcp 65001");
  // 변수 선언
  int menu_choice, count, money_in;
  int total_price, change;
  int total_qty;

  //장바구니 기능을 위한 배열 선언
  int cart[2] = {0, 0};

  //무한 반복문
  while (1)
  {
    //1. 메뉴판 출력
    printf("---CAFE KIOSK ---\n");
    printf("1. 아메리카노 (2500원) [현재 장바구니: %d잔]\n", cart[0]);
    printf("2. 카페라떼 (3000원) [현재 장바구니: %d잔]\n", cart[1]);
    printf("3. 장바구니 상품 결제하기\n");
    printf("0. 프로그램 종료\n");
    printf("원하는 기능 (메뉴) 번호를 선택하세요: ");
    scanf("%d", &menu_choice);

    // '0' 입력 시 반복 제어 break를 이용한 루프 탈출
    if (menu_choice == 0)
    {
      printf("키오스크 프로그램을 종료합니다. 이용해 주셔서 감사합니다.\n");
      break;
    }

    //2. 메뉴 선택 및 장바구니 담기 

    switch (menu_choice)
    {
      case 1: 
        printf("아메리카노 수량을 입력하세요 (최대 100잔):");
        scanf("%d", &count);
      if (count >=1 && count <= 100)
      {
        cart[0] += count;
        printf("[아메리카노 %d잔]이 장바구니에 담겼습니다.\n", count);
      }
      else
      {
        printf("수량은 1잔에서 100잔 사이만 입력 가능합니다.\n");
      }
      continue;

      case 2:
        printf("카페라때 수량을 입력하세요 (최대 100잔):");
        scanf("%d", &count);
        if (count >= 1 && count <= 100)
        {
          cart[1] += count;
          printf("[카페라떼 %d잔]이 장바구니에 담겼습니다.\n", count);
        }
        else
        {
          printf("수량은 1잔에서 100잔 사이만 입력 가능합니다.\n");
        }
      continue;

      case 3:
      if(cart[0] == 0 && cart[1] == 0)
      {
        printf("장바구니가 비어있습니다. 메뉴를 먼저 선택해주세요.\n");
        continue;
      }
      break;

      default:
        printf("없는 번호입니다. 다시 선택해주세요.\n");
        continue;
  }
  //3. 총 결제 및 금액 계산
  total_price = (cart[0] * 2500) + (cart[1] * 3000);
  total_qty = cart[0] + cart[1];
    
    printf("--- [주문 내역 확인] ---\n");
    if (cart[0] > 0)
    {  
      printf("아메리카노: %d잔\n", cart[0]);
    }
    if (cart[1] > 0)
    {
      printf("카페라떼: %d잔\n", cart[1]);
    }
    printf("총 결제 금액은 %d원입니다.\n", total_price);
    printf("-----------------------\n");

    //4. 결제 및 잔돈 계산
    printf("돈을 투입해주세요: ");
    scanf("%d", &money_in);

    if(money_in >= total_price)
    {
      change = money_in - total_price;
      printf("결제가 완료되었습니다.\n");
      printf("거스름돈은 %d원입니다. 감사합니다. \n", change);

      //5. 영수증 출력 함수 호출
      printf_receipt(cart, total_price, money_in, change);
      
      // 장바구니 초기화
      cart[0] = 0;
      cart[1] = 0;
    }

    else
    {
      printf("잔액이 %d원 부족합니다. 돈을 다시 투입해주세요.\n", total_price - money_in);
    }
  }  
  
  return 0;
}
