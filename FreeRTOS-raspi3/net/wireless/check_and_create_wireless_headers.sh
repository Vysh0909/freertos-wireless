#!/bin/bash
# -------------------------------------------------------------
# Script: check_and_create_wireless_headers.sh
# Purpose:
#   Scan net/wireless source tree for headers
#   Ignore headers that already exist
#   Create missing ones under ../porting (outside net)
# -------------------------------------------------------------

# Base directories
PROJECT_ROOT="$(pwd)/../.."  # Assuming script is run from net/wireless
SRC_DIR="net/wireless"
PORTING_DIR="$PROJECT_ROOT/porting"

mkdir -p "$PORTING_DIR"

echo "[*] Scanning source files in: $SRC_DIR"
echo "[*] Missing headers will be created in: $PORTING_DIR"
echo

found_count=0
created_count=0
total_count=0

# --- Step 1: Gather all unique include headers ---
INCLUDES=$(grep -rnoE '#include [<"].+[>"]' "$SRC_DIR" 2>/dev/null | \
           sed -E 's/.*#include [<"]([^">]+)[">].*/\1/' | sort -u)

# --- Step 2: Function to create guarded header ---
create_header_with_guard() {
    local filepath="$1"
    local filename
    filename=$(basename "$filepath")

    # Uppercase and sanitize for include guard
    local guard_name
    guard_name=$(echo "__${filename}__" | tr '[:lower:]./-' '[:upper:]___')

    mkdir -p "$(dirname "$filepath")"
    if [[ ! -f "$filepath" ]]; then
        cat <<EOF > "$filepath"
#ifndef ${guard_name}
#define ${guard_name}

/* Auto-generated stub header: ${filename} */

#endif /* ${guard_name} */
EOF
    fi
}

# --- Step 3: Loop through each header ---
while read -r hdr; do
    [[ -z "$hdr" ]] && continue
    ((total_count++))

    # Remove leading ../ for uniform paths
    hdr_clean=$(echo "$hdr" | sed 's#^\.\./##')

    # Check if header exists anywhere under project
    FOUND_PATH=$(find "$PROJECT_ROOT" -type f -name "$(basename "$hdr_clean")" 2>/dev/null | head -n 1)

    if [[ -n "$FOUND_PATH" ]]; then
        echo "[✔] Found: $hdr -> $FOUND_PATH"
        ((found_count++))
    else
        TARGET="$PORTING_DIR/$hdr_clean"
        create_header_with_guard "$TARGET"
        echo "[+] Created missing header: $TARGET"
        ((created_count++))
    fi
done <<< "$INCLUDES"

# --- Step 4: Summary ---
echo
echo "------------------------------------------------------"
echo "[📊] Total headers scanned      : $total_count"
echo "[✔] Headers found locally       : $found_count"
echo "[+] Headers created in porting  : $created_count"
echo "------------------------------------------------------"
echo "[✅] Header verification complete."

