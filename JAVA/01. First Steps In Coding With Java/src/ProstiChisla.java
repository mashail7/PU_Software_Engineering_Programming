public class ProstiChisla {

    public static void main(String[] args) {
        for (int i = 2; i <= 100; i++) {
            boolean isValid = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    isValid = false;
                    break;
                }
            }
            if (isValid == true) {
                System.out.println(i);
            }
        }
    }

}
