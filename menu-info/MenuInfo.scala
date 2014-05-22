import java.net.{HttpURLConnection,URL}
import scala.collection.JavaConversions._
import scala.xml.{XML, NodeSeq}
import java.io._
import java.util.Scanner

object MenuInfo {
	val key = "edebefbb1e7551c6205214a825f7d3c4"
	val uri = "http://api.uwaterloo.ca/v2/foodservices/menu.xml"
	val printer = new PrintWriter(new File(s"menu.txt"))

	lazy val typeMap = readMap

	def println() = {
		printer.println()
	}

	def print(a: Any) = {
		printer.print(a)
	}

	def println(a: Any) = {
		printer.println(a)
	}

	def readMap: Map[String, String] = {
		val sc = new Scanner(new File("food-types.txt"))
		var m = Map[String, String]()
		while (sc.hasNextLine) {
			val line = sc.nextLine
			val words = line.split(", ")
			for (i <- 1 until words.length)
				m = m + ((words(i), words(0)))
		}
		m
	}

	def classify(name: String): Seq[String] = {
		val nm = name.toLowerCase
		var ret = Seq[String]()
		for ((keyword, t) <- typeMap){
			if (nm.contains(keyword)) 
				ret = ret :+ t
		}
		ret
	}

	def getProducts(time: String)(implicit data: (String, String), meal: NodeSeq) = {
		val day = data._1
		val loc = data._2
		for (item <- (meal \ time \ "item")) {
			val prodName = (item \ "product_name").text
			val types = classify(prodName)
			println(s"DAY $day")
			println(s"LOCATION $loc")
			println(s"MEAL $time")
			print("TYPE")
			for (t <- types) {
				print(s" $t")
			}
			println()
			println(s"$prodName")
		}
	}

	def main(args: Array[String]): Unit = {
		val url = new URL(s"$uri?key=$key")
		val xml = XML.load(url)
		//val xml = XML.loadFile("info.xml")
		val outlets = xml \ "data" \ "outlets"
		
		for (item <- (outlets \ "item")) {
			for (outletName <- (item \ "outlet_name"); menu <- (item \ "menu")) {
				for (menuItem <- menu \ "item") {
					val day = (menuItem \ "day").text
					implicit val meals = menuItem \ "meals"
					implicit val data = (day, outletName.text)
					getProducts("lunch")
					getProducts("dinner")
				}
			}
		}
		printer.close
	}
}
