package sample;

public class Complex {

    private int re, im;

    Complex(){

    }

    Complex(int re, int im){
        this.re = re;
        this.im = im;
    }

    public Complex adunare(Complex t){
        int temp_re = this.re + t.re;
        int temp_im = this.im + t.im;
        Complex temp = new Complex(temp_re, temp_im);
        return temp;
    }

    public Complex inmultire(Complex t){
        int temp_re = this.re * t.re;
        int temp_im = this.im * t.im + this.im * t.re + this.re * t.im;
        Complex temp = new Complex(temp_re, temp_im);
        return temp;
    }

    public Complex putere(int putere){
        int i = 1;
        Complex temp = new Complex(this.re, this.im);
        Complex temp1 = new Complex(this.re, this.im);
        while(i != putere){
            temp = temp.inmultire(temp1);
            i++;
        }
        return temp;
    }

    public void afisare(){
        System.out.println(re + " + " + im + "i");
    }

    @Override
    public String toString() {
        return re + " + " + im + "i";
    }

    public boolean Equals(Complex t){
        if(this.re == t.re && this.im == t.im) return true;
        return false;
    }
}
