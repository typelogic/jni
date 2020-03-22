
class NativeSimple {
    init {
        System.loadLibrary("addnum");
    }

    external fun addnum(a:Int, b:Int): Int;
}

