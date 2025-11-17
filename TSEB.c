#include <stdio.h>
#include <stdlib.h>
 
/* * 2025년 2회차 C언어 기출 (연결 리스트 '스택' 구현)
 * 최종 답: TSEB
 */

struct node {
    char c;
    struct node* p;
};
 
// 문자열을 '거꾸로' 연결 리스트(스택)에 쌓는 함수
struct node* func(char* s) {
    struct node* h = NULL, *n;
    
    // *s가 'B', 'E', 'S', 'T' 순서로 실행
    while(*s) {
        // 1. 새 노드 n 빌리기
        n = malloc(sizeof(struct node));
        
        // 2. n에 'B' 저장 (*s) 하고 s는 다음('E')으로 이동 (++s)
        n->c = *s++; 
        
        // 3. [핵심] 새 노드 n의 다음을 '이전' head(h)로 연결
        n->p = h;
        
        // 4. [핵심] '새 노드 n'을 '새로운 head'로 업데이트
        h = n;
    }
    
    // 최종 head (즉, 'T' 노드)를 반환
    return h;
}
 
int main() {
    // n은 'T' 노드를 가리킴
    struct node* n = func("BEST");
    
    // 'T' 노드부터 'p'(다음)를 따라가며 출력
    while(n) {
        // 1. 'T' 출력 (putchar = printf("%c", ...))
        putchar(n->c);
        
        // 2. 반납할 노드를 t에 저장
        struct node* t = n;
        
        // 3. n을 다음 노드로 이동 (T->S, S->E, E->B ...)
        n = n->p;
        
        // 4. 출력한 노드('T')는 메모리에서 반납/삭제 (free)
        free(t); 
    }
    
    return 0;
}