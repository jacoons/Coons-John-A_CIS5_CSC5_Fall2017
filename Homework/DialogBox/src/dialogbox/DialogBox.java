package dialogbox;

import javax.swing.JOptionPane;

public class DialogBox {


    public static void main(String[] args) {
      
        float sum;  
        
        String number_1 = JOptionPane.showInputDialog("Enter a number nigga:");
        
        String number_2 = JOptionPane.showInputDialog("Enter another number nigga:");       
       
        
        Float number1 = Float.valueOf(number_1);
        Float number2 = Float.valueOf(number_2);
        
        sum = number1 + number2;
        
        String message = String.format("The sum of the two numbers you chose is: %n%f", sum);
           
       
        JOptionPane.showMessageDialog(null, message);
        
        
       
        
    }
    
}
 