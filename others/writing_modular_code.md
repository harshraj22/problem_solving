

<b>Some Benchmarks for modularity</b>:

1. How many times are you [rewriting similar code](http://en.wikipedia.org/wiki/Don't_repeat_yourself) for doing a particular task?
2. How much do you have to [refactor your code](http://en.wikipedia.org/wiki/Code_refactoring) when you change some part of your program?
3. Are the files <b>small and easy</b> to navigate through?
4. Are the [application modules](http://en.wikipedia.org/wiki/Subroutine) performing adequately and independently as and when required?
5. Is your code <b>minimally disastrous</b>? Does all hell break lose when you delete just one function or variable? <b>Do you get 20-odd errors upon re-naming a class?</b> (To examine this, you can implement a <b>stacking mechanism</b> to keep trace of all the hops in your application)
6. How near is the code to <b>natural language usage</b>? (i.e. modules and their subcomponents represent more real world objects without giving much concern to net source file size).
For more ideas check out [this blurb about modularity](http://web.archive.org/web/20090323235054/http://www.csse.monash.edu.au/courseware/cse2304/hndtC.html) and this one on [software quality](http://en.wikipedia.org/wiki/Code_quality)

As for your concern on <b>making your code more modular first</b> you should ask yourself the above questions, obtain specific answers for them and then have a look at [this](http://www.eng.fsu.edu/~dommelen/courses/cpm/notes/progreq/node2.html).

The <b>basic philosophy</b> is to break down your application into as small of code fragments as possible, arranged neatly across a multitude of easily understandable and accessible directory layouts.

Each method in your application <b>must do no more than the minimum quanta of processing needed</b>. Combining these methods into more and more macro level methods should lead you back to your application





[reference](https://stackoverflow.com/a/1444271)
