(실습 5) 포인터

내용: 아래와 같은 기능을 포인터를 이용하여 구현하시오.

    1) 다음과 같이 add함수를 호출하면 x와 y의 값을 더해서 sum 에 넣는 프로그램을 작성하시오.

        int x=4, y=5, sum;
        add(x, y, &sum); 
        printf("sum=%d\n",sum);

![20200930010009_pointer_add](https://github.com/qlkdkd/DataStruct/assets/71871927/976f4a3e-372e-42df-8737-174ee9200831)
[답안 보기](https://github.com/qlkdkd/DataStruct/blob/main/week6/practice6_1/practice6_1/FileName.c)
![image](https://github.com/qlkdkd/DataStruct/assets/71871927/ac49f6f9-a86a-44a4-aa68-7448e57f3e72)



    2) 포인터 변수 num을 선언하고 malloc 으로 10개의 정수를 저장할 공간을 확보한 후 해당 변수에
       1~100까지 무작위 정수를 할당하고 add 함수에 넘겨주어 add 함수에서 모든 숫자를 더해서 return 해주는
       프로그램을 작성하시오.

       int *num;
       num = (int *) malloc(sizeof(num)*10);
       if(num == (int *) NULL) {
          fprintf(stderr,"malloc fail!!!\n");
          exit(1);
       }
       ...
       ...
       ...

![20200930010931_num_add](https://github.com/qlkdkd/DataStruct/assets/71871927/07082198-c432-4ee0-bd69-7664e4076302)


    3) 두 개의 문자열을 합치는 프로그램을 작성하시오.

        char str1[10]="hello", str2[10]="world!!!", *p;
        p = (char *) malloc(sizeof(char)*20);
        if(p == (char *) NULL) {
           fprintf(stderr,"malloc fail!!!\n");
           exit(1);
        }
        concat(p, str1, str2);
        printf("%s \n",p);

![20200930012447_concat](https://github.com/qlkdkd/DataStruct/assets/71871927/74b4aa55-7847-4abc-8916-38df75de906f)


    4) 두 개의 문자열을 저장하는 배열이 있다. 하나의 포인터 변수가 두 개의 문자열 중 하나를 
       가리키게 하는 함수 set_pointer 프로그램을 작성하시오.

        char strings[2][10] = {"Hello", "World"};
        char *p;

        set_pointer(&p, 0);
        printf("%s \n", p);
        set_pointer(&p, 1);
        printf("%s \n", p);

 ![20200930012503_double_pointer](https://github.com/qlkdkd/DataStruct/assets/71871927/246930b5-cdd6-44d0-862d-72ca8cd0c32c)


       
