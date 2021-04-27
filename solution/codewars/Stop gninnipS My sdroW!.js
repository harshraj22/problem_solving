// https://www.codewars.com/kata/5264d2b162488dc400000001/train/javascript

function spinWords(string){
  //TODO Have fun :)
  var lst = string.split(' ');
  lst = lst.map(word => {
    if (word.length >= 5) return word.split('').reverse().join('');
    return word;
  });
  
  return lst.join(' ');
}