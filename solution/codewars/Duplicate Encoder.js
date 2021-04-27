// https://www.codewars.com/kata/54b42f9314d9229fd6000d9c/train/javascript

function duplicateEncode(word){
    var freq = {}
    
    word.split('').forEach( ch => {
      ch = ch.toLowerCase();
      freq[ch] = freq[ch] ? freq[ch] + 1: 1;
    });
  
    encode = '';
    word.split('').forEach( ch => {
      ch = ch.toLowerCase();
      encode += freq[ch] <= 1 ? '(': ')';
    });
  
    return encode;
}
