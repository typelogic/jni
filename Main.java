
class Main
{
    static
    {
        System.loadLibrary("native");
    }

    public native int addnum(int a, int b);

    public static void main(String args[])
    {
        Main obj = new Main();
        int sum = obj.addnum(3, 4);
        System.out.println("sum = " + sum);
    }
}
