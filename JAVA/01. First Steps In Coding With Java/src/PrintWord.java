import javax.swing.*;

public class PrintWord {

    public static void main(String[] args) {

        int kurs;

        //Scanner vhod = new Scanner(System.in);
        //System.out.print("Kurs: ");
        //kurs = vhod.nextInt();

        kurs = Integer.parseInt(JOptionPane.showInputDialog("Kurs: "));

        System.out.println("SI");
        System.out.println(kurs + " kurs");
        System.out.println("redovno");
    }

}
