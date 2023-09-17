int dataTypes(string type) {
	if (type=="Integer" || type=="Float") return 4;
	if (type=="Long" || type=="Double") return 8;
	if (type=="Character") return 1;
}