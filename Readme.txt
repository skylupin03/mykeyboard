1.  k20emul ; 최초 K20에 F411보드를 붙여서 QMK 올림 
              - custom key & LED
              - 3731 LED Matrix

2. k20emul2 ; F072에서 I2C동작을 안하여 따로 만들어 테스트 함 - 이게 최종
                 - 디지털엔코더 추가

3.  tauchef ; durgod 프로젝트를 그대로 복사하여 테스트하고
                - 컴파일 후 elf파일이 안만들어져서 4번을 만들어 테스트
                - LED를 동작시키는데 안되어 2번으로 한참 연구
                - k310 LED 동작완료 최종
                
4.  tauchef2 ; K310 LED 동작완료 (계속 개발중)
                 led애니메이션 역스텝함수, 마우스, 다이나믹 매크로, 매트릭스led에 스테터스led제어, 
          10/31 -> 윈모드-맥모드, 맥키 추가, Via에서 layer 변경에러 수정
                 
terrazzo ; terrazzo를 K20에 이식하여 동작을 검토함