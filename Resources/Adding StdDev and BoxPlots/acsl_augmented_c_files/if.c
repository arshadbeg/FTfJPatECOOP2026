if(0 <= nextNewLine && nextNewLine < nextSpace) {
      if(nextNewLine - lastChange > length && lastSpace >= 0) {
	s[lastSpace] = '\n';
      }
      lastChange = lastSpace = nextNewLine;
    } else {
      if(nextSpace - lastChange > length) {
	if(lastChange == lastSpace) {
	  s[nextSpace] = '\n';
	  lastChange = lastSpace = nextSpace;
	} else {
	  s[lastSpace] = '\n';
	  lastChange = lastSpace;
	}
      } else {
	lastSpace = nextSpace;
      }
    }
  }
  return;
}