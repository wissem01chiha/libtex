---
title: Code Samples
nav_order: 5
---

# Code Samples

## Basic Example: Writing Your First LaTeX Document

```c
#include <tex/tex.h>
#include <stdio.h>

tex_error_t   err = TEX_ENONE;
tex_document *doc = document_create(&err);

document_set_title(doc, "my-title");
document_set_author(doc, "me!");

tex_error_t write_err = document_fs_write_default(doc);
if (write_err != TEX_ENONE) {
    printf("Failed to write document: error code %d\n", write_err);
}
```

## Document Metadata

### Including title, author and date information

## Comments

### Creating Comments

### Adding Comments

[NOT SUPPOrted YET]

## Lists

### Creating Lists

### Adding Lists

[NOT SUPPOrted YET]

## Tables 

### Creating tables

### Adding Tables


## Chapters and sections

### Creating Chapters and sections

