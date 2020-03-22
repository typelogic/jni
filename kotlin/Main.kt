
fun main() {
    var a: Int = 3; // assign first coz it seg faults
    var b: Int = 4; // dunno why
    var sum = NativeSimple().addnum(a,b)
    println("sum = " + sum);
}
