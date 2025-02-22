plugins {
    id("java")
    id("application")
}

group = "org.example"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

dependencies {
    testImplementation(platform("org.junit:junit-bom:5.10.0"))
    testImplementation("org.junit.jupiter:junit-jupiter")
}

application {
    mainClass.set("com.example.Main") // Change to your actual main class
}

tasks.jar {
    manifest {
        attributes["Main-Class"] = "com.example.Main" // Change to your actual main class
    }
}

tasks.test {
    useJUnitPlatform()
}