fun readInts(separator: Char = ' ') = readLine()!!.split(separator).map(String::toInt)

fun main(vararg args: String) {
  val (a, b) = readInts()
  println(a + b)
}