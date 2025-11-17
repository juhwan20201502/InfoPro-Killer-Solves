/*
 * Java OOP 상속 (다형성) '킬러' 함정
 * 리모콘 3가지 규칙 (변수 vs static vs non-static)
 * 최종 답: 영웅 / 질리언
 */
public class HeroZilean { // 파일 이름과 동일해야 함

    public static class Hero {
        String name = "영웅"; // [!] 변수
        
        public String getName() { // [!] non-static 메서드
            return name;
        }
    }

    public static class Zilean extends Hero {
        String name = "질리언"; // [!] 변수
        
        public String getName() { // [!] non-static 메서드
            return name;
        }
    }

    public static void main(String[] args) {
        
        // 리모콘: Hero, 실제 객체: Zilean
        Hero h = new Zilean();
        
        // [1] 변수 -> '리모콘'(Hero)을 따름
        System.out.println(h.name);     
        
        // [2] non-static 메서드 -> '실제 객체'(Zilean)를 따름
        System.out.println(h.getName()); 
    }
}