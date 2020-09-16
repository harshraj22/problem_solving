`"Code should be self-documenting, that is, your naming should make it obvious what something does. exmaple"`

```javascript
public boolean shouldConsiderAbbreviating(List<String> someNames) {
  for (String eachName : someNames) {
    if (isTooLong(eachName)) {
      return true;
    }
  }
  return false;
}
```
   - [src](https://softwareengineering.stackexchange.com/a/130979)

Read a good post about naming conventions [here](https://dev.to/somedood/a-grammar-based-naming-convention-13jf)

Read about **Design Patterns** to know standard design problems and write maintainable code.
