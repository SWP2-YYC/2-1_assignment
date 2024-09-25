#define PIN_LED 13
unsigned int count, toggle;

void setup() {
  pinMode(PIN_LED, OUTPUT);  // 세미콜론 추가
  Serial.begin(115200);  // 시리얼 포트 초기화
  while (!Serial) {
    ;  // 시리얼 포트가 연결될 때까지 대기
  }
  Serial.println("Hello World!");
  count = toggle = 0;
  digitalWrite(PIN_LED, toggle);  // LED 끄기
}

void loop() {
  Serial.println(++count);
  toggle = toggle_state(toggle);  // LED 상태 변경
  digitalWrite(PIN_LED, toggle);  // LED 상태 업데이트
  delay(1000);  // 1초 대기
}

int toggle_state(int toggle) {
  return !toggle;  // 토글 값 반전
}
